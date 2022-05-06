FROM debian:buster

LABEL email="soum@student.42seoul.kr"
LABEL name="soum"
LABEL version="1.0"
LABEL description="wordpress + php-fpm"

RUN apt-get update -y && apt-get install -y php-fpm && apt-get install -y php-mysql && apt-get install -y wget
RUN wget https://wordpress.org/latest.tar.gz && tar -zxvf latest.tar.gz
RUN mkdir /var/run/php
RUN perl -p -i -e '$.==37 and print "listen = 172.17.0.3:9000\n"' /etc/php/7.3/fpm/pool.d/www.conf
COPY ./conf/wp-config.php /wordpress
#RUN perl -pi -e 's/listen = /run/php/php7.3-fpm.sock/listen = 172.17.0.2:9000/g' /etc/php/7.3/fpm/pool.d/www.conf
#RUN cp /wordpress/wp-config-sample.php /wordpress/wp-config.php
#RUN perl -pi -e 's/database_name_here/wordpress/g' /wordpress/wp-config.php
#RUN perl -pi -e 's/username_here/soum/g' /wordpress/wp-config.php
#RUN perl -pi -e 's/password_here/12345/g' /wordpress/wp-config.php
#RUN perl -pi -e 's/localhost/172.17.0.2/g' /wordpress/wp-config.php
RUN mkdir -p /var/www/soum/html
RUN cp -r /wordpress/* /var/www/soum/html

CMD service php7.3-fpm start && tail -f dev/null

EXPOSE 9000
