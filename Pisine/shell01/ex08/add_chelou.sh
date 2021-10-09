echo "obase=13;ibase=5;$FT_NBR1+$FT_NBR2" | tr "mrdoc\'\"\?\!" "012340234" | tr "\\" "1" | sed 's/3/o/1' | bc | tr "0123456789ABC" "gtaio luSnemf"
