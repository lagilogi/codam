FROM debian:bookworm

COPY ./tools/nginx-script.sh /
COPY ./config/nginx.conf /

RUN apt update -y && apt upgrade -y && \
    apt install -y nginx openssl tini curl && \
	chmod +x /nginx-script.sh && \
	rm -rf /var/lib/apt/lists/*

EXPOSE 443

ENTRYPOINT ["/usr/bin/tini", "--"]

CMD ["/nginx-script.sh"]