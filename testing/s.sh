g++ main.cpp -o a; g++ brute.cpp -o brute;
for ((i = 1; ; ++i)); do 
	echo test $i
	./gen $i > int 
	./a < int > out1
	./brute < int > out2
	diff -w out1 out2 || break
done
