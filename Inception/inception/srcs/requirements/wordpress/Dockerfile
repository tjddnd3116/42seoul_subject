# base 이미지
FROM debian:buster

# 이미지 정보
LABEL email="soum@student.42seoul.kr"
LABEL name="soum"
LABEL version="1.0"
LABEL description="wordpress + php-fpm"

# php, mariadb-client 설치
RUN apt-get update -y && apt-get install -y php-fpm && apt-get install -y php-mysql && apt-get install -y wget && apt-get install -y mariadb-client

# wp-cli 설치
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

# wordpress다운 및 설치, 유저추가를 위한 스크립트 복사
COPY ./tools/conf.sh /
RUN chmod +x /conf.sh

# 이미지 실행시 스크립트 실행
CMD /conf.sh
