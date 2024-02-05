n, m = map(int, input().split())

pack_list = []
one_list  = []

for i in range(m):
    pack_price, one_price = map(int, input().split())
    pack_list.append(pack_price)
    one_list.append(one_price)

pack   = min(pack_list)
one    = min(one_list)

def string():

    need_string = n
    money = 0

    while need_string > 0:
        
        if pack < 6 * one and pack < need_string * one:
            need_string -= 6
            money += pack
        else:
            need_string -= 1
            money += one

    print(money)

string()