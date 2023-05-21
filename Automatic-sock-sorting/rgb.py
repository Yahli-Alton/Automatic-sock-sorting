import time
import cv2
import numpy as np
from camera import dominant_color

file_path = "putty.log"
# file = open(file_path, "w")
# file = open(file_path, "r")

while True:
    # print(split_contents)

    # Do something with the split contents
    # for item in split_contents:
    #     print(item)
    # print(split_contents)
    item = dominant_color()
    print(item)
    if len(item) == 3:
        if (item[0] == '' or item[1] == '' or item[2] == ''): 
            continue
        item = [int(i) for i in item]
        print(item)
        # time.sleep(1)
        rgb_matrix = np.array(item)  # 

        # image = np.reshape(rgb_matrix, (1)).astype(np.uint8)
        # image = rgb_matrix.reshape(rgb_matrix, 1).astype(np.uint8) # why does this not work?
        image = np.array(rgb_matrix, dtype=np.uint8) # why is it black and white? I want one pixel rgb color
        image = image.reshape(1, 1, 3)
        cv2.namedWindow("RGB Matrix", cv2.WINDOW_NORMAL)
        cv2.imshow("RGB Matrix", image)
        cv2.waitKey(0)


# cv2.waitKey(0)
# cv2.destroyAllWindows()

file.close()