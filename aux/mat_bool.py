import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('mapa_colisao.png')

img = cv2.resize(img, (800, 450)) 
height, width = img.shape[:2]

with open('mat.txt', 'w') as f:
    f.write(str(height));
    f.write(' ');
    f.write(str(width));
    f.write('\n')

    for i in range(height):
        for j in range(width):
            #print(img[i, j])
            if((img[i, j]==[255,255,255]).all()):
                #print(1, end=' ')
                f.write('1 ');
            else:
                #print(0, end=' ')
                f.write('0 ')
        #print()
        f.write('\n')
f.close()

cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()