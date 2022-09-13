#!/bin/bash
perl -p -i -e '$.==19 and print "port = 3306\n"' /etc/mysql/mariadb.conf.d/50-server.cnf
perl -pi -e 's/127.0.0.1/0.0.0.0/g' /etc/mysql/mariadb.conf.d/50-server.cnf

echo "CREATE DATABASE $MYSQL_DATABASE;\
		GRANT ALL PRIVILEGES ON *.* TO '$MYSQL_USER'@'wordpress.srcs_inception_net' IDENTIFIED BY '$MYSQL_PASSWORD';\
        FLUSH PRIVILEGES;\
		ALTER USER '$MYSQL_ROOT'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';" > mariadb.sh
