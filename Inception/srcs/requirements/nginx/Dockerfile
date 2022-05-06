FROM debian:buster

LABEL email="soum@student.42seoul.kr"
LABEL name="soum"
LABEL version="1.0"
LABEL description="nginx"

RUN apt-get update -y && apt-get install -y nginx \
		&& apt-get install openssl && apt-get install -y vim
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=42Seoul/CN=42.fr" -keyout /etc/ssl/private/soum.key -out /etc/ssl/certs/soum.crt
RUN rm /etc/nginx/sites-available/default
COPY ./conf/default /etc/nginx/sites-available/
# RUN echo "server {\n\
#         listen 443 ssl;\n\
#         listen [::]:443 ssl;\n\
#         server_name soum.42.fr;\n\
#         ssl on;\n\
#         ssl_certificate /etc/ssl/certs/soum.crt;\n\
#         ssl_certificate_key /etc/ssl/private/soum.key;\n\
#         root /var/www/soum/html;\n\
#         index index.nginx-debian.html index.html index.php;\nlocation / {\n\
#             try_files \$uri \$uri/ =404;\n\
#         }\n\
#         location ~ \.php\$ {\n\
#         try_files \$uri =404;\n\
#         fastcgi_split_path_info ^(.+\.php)(/.+)\$;\n\
#         fastcgi_pass 172.17.0.3:9000;\n\
#         root /var/www/soum/html;\n\
#         fastcgi_index index.php;\n\
#         include fastcgi_params;\n\
#         fastcgi_param SCRIPT_FILENAME \$document_root\$fastcgi_script_name;\n\
#         fastcgi_param PATH_INFO \$fastcgi_path_info;\n\
#     }\n\
#     }" > /etc/nginx/sites-available/default
RUN nginx -t
# RUN perl -pi -e 's/# listen/listen/g' /etc/nginx/sites-available/default
# RUN perl -p -i -e '$.==30 and print "ssl on;\n ssl_certificate /etc/ssl/certs/localhost.dev.crt;\nssl_certificate_key /etc/ssl/private/localhost.dev.key;\n"' /etc/nginx/sites-available/default
EXPOSE 443

CMD nginx -g "daemon off;"
