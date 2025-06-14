//1
start s
end e



s _ -> e 0 N
s 0 -> a A R
s 1 -> b A R

a 0 -> a x R
a 1 -> b x R
a _ -> u _ L

b 0 -> b x R
b 1 -> a x R
b _ -> v _ L

u x -> u _ L
u A -> e 0 N

v x -> v _ L
v A -> e 1 N

