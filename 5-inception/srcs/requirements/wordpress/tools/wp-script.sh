#!/bin/bash

set -e

mkdir -p /var/www/html

if [ ! -f /var/www/html/wp-config.php ]; then
	echo "Setting up wordpress stuff"

	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp-cli.phar

	cd /var/www/html

	wp-cli.phar core download --allow-root

	touch /.wp_setup_done
fi

DB_USER_PASSWORD=$(cat /run/secrets/db_user_password)
WP_ADMIN_PASSWORD=$(cat /run/secrets/wp_admin_password)
WP_USER_PASSWORD=$(cat /run/secrets/wp_user_password)

until mysql -h"${DB_HOST}" -u"${DB_USER}" -p"${DB_USER_PASSWORD}" -e "SELECT 1;" &>/dev/null; do
    sleep 2
done

if [ ! -f /var/www/html/wp-config.php ]; then

	echo "Inside config part"

	cd /var/www/html

	wp-cli.phar config create \
	--path="/var/www/html" \
	--dbname="${DB_NAME}" \
	--dbhost="${DB_HOST}" \
	--dbuser="${DB_USER}" \
	--dbpass="${DB_USER_PASSWORD}" \
	--allow-root

	wp-cli.phar core install \
	--path="/var/www/html" \
	--url="${DOMAIN_NAME}" \
	--title="My Inception Project" \
	--admin_user="${WP_ADMIN}" \
	--admin_password="${WP_ADMIN_PASSWORD}" \
	--admin_email="${WP_ADMIN_EMAIL}" \
	--allow-root

	wp-cli.phar user create ${WP_USER} ${WP_USER_EMAIL} \
	--path="/var/www/html" \
	--user_pass="${WP_USER_PASSWORD}" \
	--role=author \
	--allow-root
fi

echo "Starting php-fpm8.2 -F"
exec php-fpm8.2 -F
