import cv2
import numpy as np
from matplotlib import pyplot as plt
import serial
import time
PRECENT = 0.1
"""
arduino = serial.Serial(port='COM5', baudrate=9600, timeout=.1)
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data
"""


def dominant_color():
    
    # while True:
    # time.sleep(1)
    # Capture the video frame
    # by frame

    # Display the resulting frame
    # cv2.imshow('frame', frame)

    # the 'q' button is set as the
    # quitting button you may use any
    # desired button of your choice



    # Convert image to RGB color space
    image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    # Flatten the image
    pixels = image.reshape(-1, 3)

    # Define the number of clusters (dominant colors)
    K = 1

    # Apply K-means clustering
    _, labels, centers = cv2.kmeans(pixels.astype(np.float32), K, None, criteria=(cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10, 1.0), attempts=10, flags=cv2.KMEANS_RANDOM_CENTERS)

    # Convert cluster centers to uint8 and reshape
    dominant_colors = np.uint8(centers.reshape(1, K, 3))

    # Display dominant colors
    for color in dominant_colors[0]:
        return color

if __name__ == "__main__":
    vid = cv2.VideoCapture(1)
    while True:
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
        ret, frame = vid.read()
        color = dominant_color()
        mask = cv2.inRange(frame, (color[0],color[1],color[2]), (item + 10 for item in color))
        cv2.imshow("Mask Applied to Image", mask)

	# BGR
    # pink_mask = cv2.inRange(frame, (30, 30, 90), (90, 90, 255))
    # cv2.imshow("Mask Applied to Image2", pink_mask)
    # number_of_white_pix = np.sum(pink_mask == 255)
    # number_of_black_pix = np.sum(pink_mask == 0)

    # if (number_of_white_pix / number_of_black_pix) > PRECENT:
    #     print("pink")
    # # can you give me color mask for light blue?

    # purple_mask = cv2.inRange(frame, (0,0,0), (200, 200, 200))
    # cv2.imshow("Mask Applied to Image3", purple_mask)
    # number_of_white_pix = np.sum(purple_mask == 255)
    # number_of_black_pix = np.sum(purple_mask == 0)

    # if (number_of_white_pix / number_of_black_pix) > PRECENT:
    #     print("blue")

	# red_mask = cv2.inRange(frame, (0, 0, 90), (70, 70, 255))
	# pink_mask = cv2.inRange(frame, (90, 45, 45), (255, 70, 70))
	# blue_mask = cv2.inRange(frame, (90, 0, 0), (255, 70, 70))
	# white_mask = cv2.inRange(frame, (90, 90, 90), (255, 255, 255))
	# black_mask = cv2.inRange(frame, (0, 0, 0), (70, 70, 70))
	# list = [red_mask, pink_mask, blue_mask, white_mask, black_mask]
	
	# cv2.imshow("Mask Applied to Image", red_mask)
	# cv2.imshow("Mask Applied to Image2", pink_mask)
	# cv2.imshow("Mask Applied to Image3", blue_mask)
	# cv2.imshow("Mask Applied to Image4", white_mask)
	# cv2.imshow("Mask Applied to Image5", black_mask)

	
	# kernel = np.ones((5, 5), np.uint8)
	# erosion = cv2.erode(red_mask, kernel, iterations=1)

	# img_dilation = cv2.dilate(erosion, kernel, iterations=1)
# for item in list:
#     cv2.imshow("Mask Applied to Image", item)
	# number_of_white_pix = np.sum(img_dilation == 255)
	# number_of_black_pix = np.sum(img_dilation == 0)
	# print('Number of white pixels:', number_of_white_pix)
	# print('Number of black pixels:', number_of_black_pix)
	# cv2.imshow("Mask Applied to Image", img_dilation)