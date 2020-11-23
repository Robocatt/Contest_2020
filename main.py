


'''



#os.system(r'D:/Programming/Contest/all_test_V2.ino')

#time.sleep(15)




os.system(r'nul>stepperf.txt')
os.system(r'nul>Hall.txt')




time.sleep(1)

import psutil

for process in (process for process in psutil.process_iter() if process.name() == "Gobetwino"): process.kill()
'''

import time
import os
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


with open('Hall.txt', 'tw', encoding='utf-8') as f:
    pass



with open('stepperf.txt', 'tw', encoding='utf-8') as p:
    pass


os.system(r'D:/Programming/Contest_2020/Gobetwino/Gobetwino.exe')













#time.sleep(12)



#os.system('taskkill /pid ')






x=[]
with open('D:\Programming\Contest_2020\stepperf.txt','r') as a:
    for line in a:
        x.append(int(line.strip()))
x =np.array(x)

y=[]
with open('D:\Programming\Contest_2020\Hall.txt','r') as b:
    for line in b:
        y.append(int(line.strip()))
y  = np.array(y)
df = pd.DataFrame({'x': x, 'y': y})
df_sorted_by_y = df.sort_values(by='y', ascending=True)
x_sorted = df['x'].values
y_sorted = df['y'].values


fig, ax = plt.subplots(figsize=(8, 6))
plt.title("График зависимости магнитного поля от угла поворота")
plt.xlabel("Градус поворота")
plt.ylabel("Значение индукции магнитного поля")
plt.grid()
plt.plot(x_sorted,y_sorted,)
plt.show()


