# base 이미지
FROM debian:buster

# build시 사용할 arg
ARG MYSQL_DATABASE
ARG MYSQL_USER
ARG MYSQL_PASSWORD
ARG MYSQL_ROOT
ARG MYSQL_ROOT_PASSWORD

# 이미지 정보
LABEL email="soum@student.42seoul.kr"
LABEL name="soum"
LABEL version="1.0"
LABEL description="mariadb"

# mariadb 설치
RUN apt-get update -y && apt-get install -y mariadb-server

COPY ./tools/conf.sh /
RUN chmod +x /conf.sh
RUN ./conf.sh

RUN service mysql start && mariadb < mariadb.sh
RUN rm mariadb.sh

CMD mysqld
