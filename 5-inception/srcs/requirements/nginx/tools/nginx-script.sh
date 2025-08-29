#!/bin/bash

set -e

mkdir -p /etc/nginx/ssl

if [ ! -f ".nginx_setup_done" ]; then
	echo "Setting up nginx"

	mv /nginx.conf /etc/nginx/conf.d/default.conf
	
	openssl req \
	-x509 \
	-nodes \
	-days 365 \
	-keyout /etc/nginx/ssl/inception.key \
	-out /etc/nginx/ssl/inception.crt \
	-subj "/C=NL/ST=Noord-Holland/L=Amsterdam/O=Codam/CN=${DOMAIN_NAME}"

	touch .nginx_setup_done

fi

echo "Starting nginx -g \"daemon off;\""
exec nginx -g "daemon off;"
