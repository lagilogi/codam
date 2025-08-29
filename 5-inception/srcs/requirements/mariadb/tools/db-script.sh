#!/bin/bash

set -e

mkdir -p /var/lib/mysql

if [ ! -f "/.mariadb_setup_done" ]; then
	echo "Setting up mariadb"

	mkdir -p /run/mysqld /var/lib/mysql /var/log/mysql
	chown -R mysql:mysql /run/mysqld /var/lib/mysql /var/log/mysql

	mv /db-config.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

	service mariadb start;

	sleep 5;

	DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
	DB_USER_PASSWORD=$(cat /run/secrets/db_user_password)

	mysql -u root -p$DB_ROOT_PASSWORD << EOF
	ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASSWORD';
	CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;
	CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_USER_PASSWORD';
	GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '$DB_USER'@'%';
	FLUSH PRIVILEGES;
EOF

	mysqladmin -u root -p"${DB_ROOT_PASSWORD}" shutdown;

	touch /.mariadb_setup_done
fi

echo "Starting mysqld_safe"
exec mysqld_safe;
