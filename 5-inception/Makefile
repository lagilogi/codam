NAME =				inception

COMPOSE_FILE =		./srcs/docker-compose.yml
ENV_FILE =			./srcs/.env
LOG_FILE = 			./compose-logs.txt

WORDPRESS_DATA =	${HOME}/data/wordpress
MARIADB_DATA =		${HOME}/data/mariadb


all: up

build:
	mkdir -p $(WORDPRESS_DATA) $(MARIADB_DATA)
	docker compose -p $(NAME) -f $(COMPOSE_FILE) build --no-cache

up:
	mkdir -p $(WORDPRESS_DATA) $(MARIADB_DATA)
	docker compose -p $(NAME) -f $(COMPOSE_FILE) up -d --build

down:
	docker compose -p $(NAME) -f $(COMPOSE_FILE) down

start:
	docker compose -p $(NAME) -f $(COMPOSE_FILE) start

stop:
	docker compose -p $(NAME) -f $(COMPOSE_FILE) stop

logs:
	docker compose -p $(NAME) -f $(COMPOSE_FILE) logs > $(LOG_FILE)

clean:
	docker compose -p $(NAME) -f $(COMPOSE_FILE) down --volumes --rmi all
	rm  ${LOG_FILE} || true
	sudo rm -rf ${WORDPRESS_DATA} ${MARIADB_DATA}

restart: stop start

rebuild: down up

reclean: clean up

.PHONY: all build up down start stop logs restart rebuild clean reclean prune