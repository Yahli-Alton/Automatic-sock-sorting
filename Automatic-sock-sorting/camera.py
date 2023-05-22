import cv2
import numpy as np
from matplotlib import pyplot as plt
import serial
import time
PRECENT = 0.1
COLOR_RANGE = 20
SHORT_MAX = 100 # px
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

def check_for_size():
    color = dominant_color()
    print(color)
    mask = cv2.inRange(frame, np.array((color[0] - COLOR_RANGE,color[1] - COLOR_RANGE,color[2] - COLOR_RANGE)), np.array((color[0] + COLOR_RANGE,color[1] + COLOR_RANGE,color[2] + COLOR_RANGE)))

    edges = cv2.Canny(mask, 100, 200)

    # Define the structuring element for morphological operations
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (15,15))  # Adjust the kernel size as needed

    # Perform iterative morphological closing to fill holes
    # num_iterations = 50  # Adjust the number of iterations as needed
    # closed = edges
    # for _ in range(num_iterations):
    #     closed = cv2.morphologyEx(closed, cv2.MORPH_CLOSE, kernel)

    closed = cv2.morphologyEx(edges, cv2.MORPH_CLOSE, kernel)

    # kernel = np.ones((5, 5), np.uint8)
    # erosion = cv2.erode(mask, kernel, iterations=1)
    # img_dilation = cv2.dilate(erosion, kernel, iterations=1)


    # Apply morphological opening to remove noise
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (5, 5))  # Adjust kernel size as needed
    opened = closed
    # for i in range(5):
    #     opened = cv2.morphologyEx(closed, cv2.MORPH_OPEN, kernel)

    # Find contours of the filtered region
    contours, _ = cv2.findContours(opened, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    if (len(contours)) == 0:
        cv2.imshow("Mask Applied to Image", opened)
        cv2.imshow("image", frame)
        return -1

    # Find the largest contour (assuming it corresponds to the desired object)
    largest_contour = max(contours, key=lambda c: cv2.arcLength(c, True))

    # Find the bounding box of the object
    x, y, width, height = cv2.boundingRect(largest_contour)

    # Draw a red rectangle around the object
    cv2.rectangle(frame, (x, y), (x + width, y + height), (0, 0, 255), 2)

    cv2.imshow("Mask Applied to Image", opened)
    cv2.imshow("image", frame)

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


if __name__ == '__main__':
    vid = cv2.VideoCapture(1)
    while True:
        ret, frame = vid.read()
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
        x = check_for_size()
        if (x != -1):
            arduino = serial.Serial(port='COM5', baudrate=9600, timeout=.1)
            arduino.write(bytes(x, 'utf-8'))
