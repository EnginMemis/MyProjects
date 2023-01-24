import numpy as np
import random as rand


def position(path,index,array,steps,route):

    if  path[index][0] >= 9 and path[index][1] <= 0:
        return (steps,route+[([path[index][0],path[index][1]])]) 

    root = False
    sum = False
    mul = False

    #Kare sayı kontrolü

    if array[path[index][0]][path[index][1]] == 4 or array[path[index][0]][path[index][1]] == 9:        
        root = True
    
    #Çarpma özel durumu kontrolü

    if index <= 96 and array[path[index][0]][path[index][1]] * array[path[index+1][0]][path[index+1][1]] == array[path[index+2][0]][path[index+2][1]]:
        mul = True

    #Toplama özel durumu kontrolü

    if index <= 96 and array[path[index][0]][path[index][1]] + array[path[index+1][0]][path[index+1][1]] == array[path[index+2][0]][path[index+2][1]]:
        sum = True


    #Özel durumlardan herhangi biri var ise girecek if
    if root or sum or mul:

        # 3 şartın da aynı anda sağlaması durumunda adım sayısı değerlerinin bulunacağı liste ve bu listedeki minimum adım sayısı return edilecek
        a = []

        if mul:
            #aşağı inecek adım sayısı hesaplama
            fark = min(array[path[index][0]][path[index][1]] , array[path[index+1][0]][path[index+1][1]])

            #En alt satırda değilse aşağı inme hesabı
            if path[index][0] != 9:

                #Aşağı ineceği yer matris dışında mı kontrolü
                if fark + path[index+2][0] > 9:
                    #İneceği yerin koordinatları
                    x = 9
                    y = path[index+2][1]
                    
                    j = path[index+2][0]

                    #Koordinatlardan yolun kaçıncı indexinde hesaplama fonksiyonu
                    i = search(array,path,index,x,y)

                    adim = path[i][0]-path[index][0]

                    #Gideceği yolun koordinatlarını eklenecek liste
                    yol = []
                    
                    #Koordinatların eklenmesi
                    yol += [([path[index][0],path[index][1]]) ,([path[index+1][0],path[index+1][1]]) ,([path[index+2][0],path[index+2][1]])]
                    
                    #Aşağı inerken indiği yolların da listeye eklenmesi
                    while j < path[i][0]-1:
            
                        yol += [([j+1,y])]
                        j += 1

                    #Dönen yolun değerini listeye ekleme
                    a += [position(path, i, array, steps + adim + 2 ,route+yol)]

                #Aşağı indiğinde matris dışına çıkmıyorsa
                else:
                    x = path[index+2][0]
                    y = path[index+2][1]

                    yol = []
                    
                    j = x
    
                    x += fark

                    i = search(array,path,index,x,y)
                    
                    yol = []

                    yol += [([path[index][0],path[index][1]]) ,([path[index+1][0],path[index+1][1]]) ,([path[index+2][0],path[index+2][1]])]

                    while j < path[i][0]-1:
            
                        yol += [([j+1,y])]
                        j += 1

                    #Özel durumu seçmesi ya da seçmemesi durumunda dallanmadaki dönecek minimum yolun hesabı
                    a += [min(position(path, i, array, steps + fark + 2,route+yol) , position(path, index + 1, array, steps + 1,route+[([path[index][0],path[index][1]])]))]

            else:
                a += [position(path, index + 1, array, steps + 1,route+[ ([path[index][0],path[index][1]]) ])]


        #Kare Sayı ise
        if root:
            #En alt satırda bulunmuyorsa 1 satır aşağı inecek
            if path[index][0] != 9:
                #Gideceği yolun koordinatları
                x = path[index][0] + 1
                y = path[index][1]
                
                #Koordinatlardan yoldaki indexini bulma
                i = search(array,path,index,x,y)

                #Dallanma durumunda özel durumu seçme ya da seçmemesi halinde minimum bulunması
                a += [min(position(path,i, array, steps + 1,route+[([path[index][0],path[index][1]])]) , position(path, index + 1, array, steps + 1,route+[([path[index][0],path[index][1]])]))]
            else:
                #En alt satırda ise yola normal devam etme
                a += [position(path, index + 1, array, steps + 1,route+[([path[index][0],path[index][1]])])]
                


        #Toplama Özel durumu
        if sum:

            #Gideceği adım sayısının hesaplanması
            fark = array[path[index+2][0]][path[index+2][1]]

            #Gideceği yol matris dışına çıkıyor mu kontrol edilmesi
            fark = min(99,index + fark + 2)

            yol = []

            #Atlayacağı koordinata gelene kadar eklenmesi gereken yolların koordinatlarının eklenmesi
            yol += [([path[index][0],path[index][1]]) ,([path[index+1][0],path[index+1][1]]) ,([path[index+2][0],path[index+2][1]])]


            a += [position(path, fark, array, steps + 3,route+yol)]


        # 3 özel durumdan da dönen adım sayılarından minimum değerin return edilmesi
        return min(a)

    else:
        #Herhangi bir özel durum yoksa yoluna devam etme
        return position(path, index + 1, array, steps + 1,route+[([path[index][0],path[index][1]])])
            
            

#Verilen koordinatlardan path listesindeki indexini bulan fonksiyon
def search(array,path,index,x,y):

    flag = 1
    i = 0
    while flag:
        if path[i][0] == x and path[i][1] == y:
            flag = 0
        else:
            i += 1

    return i





array = np.zeros((10,10),dtype=np.int16)
mark = np.zeros((10,10),dtype=np.int16)

#random matris oluşturma
for i in range(10):
    for j in range(10):
        array[i][j] = rand.randint(2,15)

#Matriste tek tek dolanacağı yolların koordinatlarının tutulduğu liste
path = []


i = 0
j = 0
path.append([0,0])


#Path listesinin oluşturulması
while i != 9 or j != 0:
    if i % 2 == 0 and j == 9:
        i += 1

    elif i % 2 == 1 and j == 0:
        i += 1

    else:
        if i % 2 == 0:
            j += 1
        else:
            j -= 1

    path.append([i,j])



#Recursive fonksiyon çağrımı
(steps,route) = position(path,0,array,0,[])


for i in range(len(route)):
    mark[route[i][0]][route[i][1]] = -1


x = 0

#En kısa yolun yazdırılması
for i in range(10):
    for j in range(10):
        if mark[i][j] == -1:
            print("{:3}*".format(array[i][j]),end="")
            x += 1
        else:
            print("{:4}".format(array[i][j]),end="")
    print()

print(f"Yol Uzunluğu: {x}")


