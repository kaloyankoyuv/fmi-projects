import cv2  # Not actually necessary if you just want to create an image.
import numpy as np
f = open("output.txt")
lines = f.readlines()
h = int(lines[0])
w = int(lines[1])
image = np.zeros((h,w,3), np.uint8)

c = 2

for i in range(h):
	for j in range(w):
		image[i, j] = [int(color) for color in lines[c].split()]
		c += 1

cv2.imshow("A New Image", image)
cv2.waitKey(0)
