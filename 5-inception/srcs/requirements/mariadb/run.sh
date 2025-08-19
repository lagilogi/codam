docker stop mariadb_container
docker rm mariadb_container
docker rmi mariadb_container
docker volume prune -af
docker build -t mariadb_container .
docker run --name mariadb_container -d mariadb_container