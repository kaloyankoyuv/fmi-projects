import sys
import cv2
img = cv2.imread(sys.argv[1], cv2.IMREAD_ANYCOLOR)
f = open("input.txt", 'w')

(h, w) = img.shape[:2]
f.write("{}\n".format(h))
f.write("{}\n".format(w))
for i in range(h):
	for j in range(w):
		f.write("{} {} {}\n".format(img[i, j][0], img[i, j][1], img[i, j][2]))

f.close()
