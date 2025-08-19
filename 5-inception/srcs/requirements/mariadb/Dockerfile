FROM debian:bookworm

COPY ./tools/db-script.sh /
COPY ./config/db-config.cnf /

RUN apt-get update -y && \
    apt-get install -y mariadb-server \
    mariadb-client \
	tini && \
    chmod +x /db-script.sh

EXPOSE 3306

ENTRYPOINT ["/usr/bin/tini", "--"]

CMD ["/db-script.sh"]