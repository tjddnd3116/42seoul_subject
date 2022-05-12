FROM debian:buster

LABEL email="soum@student.42seoul.kr"
LABEL name="soum"
LABEL version="1.0"
LABEL description="wordpress + php-fpm"

RUN apt-get update -y && apt-get install -y php-fpm && apt-get install -y php-mysql && apt-get install -y wget

RUN wget https://wordpress.org/latest.tar.gz && tar -zxvf latest.tar.gz
#RUN chown -R root:root /wordpress/*

COPY ./tools/conf.sh /
RUN chmod +x /conf.sh
COPY ./conf/wp-config.php /wordpress

CMD /conf.sh

EXPOSE 9000
