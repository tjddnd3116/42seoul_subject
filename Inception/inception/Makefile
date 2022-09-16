DOC_COM = docker-compose -f
DOC_YML = docker-compose.yml
DOC_YML_PATH = ./srcs/
DB_PATH = /home/soum/data/mariadb
WP_PATH = /home/soum/data/wordpress
RM_VOL = docker volume rm
RM_IMG = docker rmi -f


all: build up

build:
	@docker-compose -f ./srcs/docker-compose.yml build

up:
	@mkdir -p $(DB_PATH);\
	mkdir -p $(WP_PATH);\
	$(DOC_COM) $(DOC_YML_PATH)$(DOC_YML) up -d

down:
	@docker-compose -f ./srcs/docker-compose.yml down

clean: down
	@$(RM_IMG) $$(docker images -q);\
	$(RM_VOL) $$(docker volume ls -q);

re: clean build up

.PHONY: all build up down re clean
