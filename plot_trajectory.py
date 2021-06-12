import matplotlib.pyplot as plt

s = input("enter file path :")
path = s.replace('\\', '/')



with open(path) as f:
    content = f.readlines()

LON = []
LAT = []

for line in content:
    if line[0]=='=':
        continue
    if line == '\n':
        continue

    if line == '0':
        continue

    line1 = line.split(sep=',')

    lon_string = line1[0].split()

    lat_string = line1[1].split()

    

    longitude = int(lon_string[0]) + float(int(lon_string[1])/60) +  float(int(lon_string[2])/6000000)
    latitude = int(lat_string[0]) + float(int(lat_string[1])/60) +  float(int(lat_string[2])/6000000)
    LON.append(longitude)
    LAT.append(latitude)

#origin_x = LAT[0]
#origin_y = LON[0]
#
#for i in range(len(LAT)):
#    LAT[i] -= origin_x
#
#for i in range(len(LON)):
#    LON[i] -= origin_y
    


    

plt.plot(LON,LAT)
plt.plot(LON[0],LAT[0],'*g')
plt.show()