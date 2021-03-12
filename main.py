import subprocess
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import pandas as pd



open('D:/Programming/Contest_2020/Hall.txt', 'w').close()
open('D:/Programming/Contest_2020/stepperf.txt', 'w').close()
subprocess.Popen('D:\Programming\Contest_2020\start.bat', cwd='D:\Programming\Contest_2020', creationflags=subprocess.CREATE_NEW_CONSOLE)
subprocess.call("D:/Programming/Contest_2020/Gobetwino/Gobetwino.exe")

x=[]
with open('D:/Programming/Contest_2020/stepperf.txt','r') as f:
    for line in f:
        x.append(line.strip())
x =np.array(x)

y=[]
with open('D:/Programming/Contest_2020/Hall.txt','r') as b:
    for line in b:
        if line.strip()!='\n':
            y.append(line.strip())

for i in range (len(y)):
    y[i]=float(y[i])   
y  = np.array(y)


df = pd.DataFrame({'x': x, 'y': y})
df_sorted_by_y = df.sort_values(by='y', ascending=True)
x_sorted = df['x'].values
y_sorted = df['y'].values
fig, ax = plt.subplots(figsize=(10, 10))
ax.xaxis.set_major_locator(ticker.MultipleLocator(15))
plt.title("График зависимости магнитного поля от угла поворота")
plt.xlabel("Градус поворота магнита, °")
#мТл? 
plt.ylabel("Значение индукции магнитного поля, мТл ")
plt.grid()
plt.plot(x_sorted,y_sorted)
plt.show()