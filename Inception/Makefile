all: build up

build:
	@sudo docker-compose -f ./srcs/docker-compose.yml build

up:
	@sudo mkdir -p /home/soum/data/mariadb;\
	sudo mkdir -p /home/soum/data/wordpress;\
	sudo docker-compose -f ./srcs/docker-compose.yml up -docker

down:
	@sudo docker-compose -f ./srcs/docker-compose.yml down

re: clean build up

clean: down
	@sudo docker rmi -f $$(sudo docker images -q);\
	sudo docker volume rm $$(sudo docekr volume ls -q);\
	sudo rm -rf /home/soum/data

ps:
	@sudo docker-compose -f ./srcs/docker-compose.yml ps;\
	sudo docker volume ls;\
	sudo docker network ls;\
	sudo docker-compose -f ./srcs/docker-compose.yml top

image:
	@sudo docker-compose -f ./srcs/docker-compose.yml images

config:
	@sudo docker-compose -f ./srcs/docker-compose.yml config

.PHONY: all build up down re clean image config
