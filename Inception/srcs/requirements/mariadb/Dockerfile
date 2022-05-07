FROM debian:buster

LABEL email="soum@student.42seoul.kr"
LABEL name="soum"
LABEL version="1.0"
LABEL description="mariadb"

RUN apt-get update -y && apt-get install -y vim && apt-get install -y mariadb-server
#RUN echo "CREATE DATABASE wordpress;\n\
#		GRANT ALL PRIVILEGES ON *.* TO 'soum'@'%' IDENTIFIED BY '12345';\n\
#		FLUSH PRIVILEGES;" > mariadb.sh
#RUN echo "bind-address = 0.0.0.0" >> /etc/mysql/conf.d/mysql.cnf
RUN perl -p -i -e '$.==19 and print "port = 3306\n"' /etc/mysql/mariadb.conf.d/50-server.cnf
RUN perl -pi -e 's/127.0.0.1/0.0.0.0/g' /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./tools/mariadb.sh /
RUN service mysql start && mariadb < mariadb.sh
RUN rm mariadb.sh
#RUN chown -R mysql:mysql /var/lib/mysql
CMD mysqld

EXPOSE 3306
