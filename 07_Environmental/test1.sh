diff -i <(echo 'SHA1 "helloworld' | ./rhasher) <(echo 'helloworld' | sha1sum)
diff -i <(echo 'MD5 "helloworld' | ./rhasher) <(echo 'helloworld' | md5sum)

