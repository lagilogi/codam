#!/bin/bash

if [ ! -f "/var/lib/mysql/.mariadb_is_setup" ]; then
	mkdir -p /run/mysqld /var/lib/mysql /var/log/mysql
	chown -R mysql:mysql /run/mysqld /var/lib/mysql /var/log/mysql

	mv /db-config.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

	service mariadb start;

	sleep 5;

	DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
	DB_USER_PASSWORD=$(cat /run/secrets/db_password)

	mysql -u root << EOF
	ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASSWORD';
	CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;
	CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_USER_PASSWORD';
	GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '$DB_USER'@'%';
	FLUSH PRIVILEGES;
EOF

	mysqladmin -u root -p"${DB_ROOT_PASSWORD}" shutdown;

	touch /var/lib/mysql/.mariadb_is_setup
	rm -rf /run/secrets/
fi

exec mysqld_safe;