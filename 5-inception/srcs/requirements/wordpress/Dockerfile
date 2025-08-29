FROM debian:bookworm

COPY ./tools/wp-script.sh /

RUN apt update -y && \
	apt install -y php8.2 php8.2-fpm php8.2-mysql php8.2-mbstring php8.2-xml mariadb-client curl tini && \
	chmod +x /wp-script.sh && \
	rm -rf /var/lib/apt/lists/*

COPY ./config/www.conf /etc/php/8.2/fpm/pool.d/www.conf

EXPOSE 9000

ENTRYPOINT ["/usr/bin/tini", "--"]

CMD ["/wp-script.sh"]