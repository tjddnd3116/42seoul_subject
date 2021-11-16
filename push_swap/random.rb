#!/usr/bin/ruby
v1 = Integer(ARGV[0])
a = (1..v1).to_a
shfled = a.shuffle
puts shfled.join(' ')

