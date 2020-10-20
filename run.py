import numpy
import cv2

def nothing(x):
    pass

cv2.namedWindow("Color Filter")
cv2.createTrackbar('Min Hue','Color Filter',0,179,nothing)
cv2.createTrackbar('Max Hue','Color Filter',179,179,nothing)
cv2.createTrackbar('Min Saturation','Color Filter',0,255,nothing)
cv2.createTrackbar('Max Saturation','Color Filter',255,255,nothing)
cv2.createTrackbar('Min Value','Color Filter',0,255,nothing)
cv2.createTrackbar('Max Value','Color Filter',255,255,nothing)

cap = cv2.VideoCapture(0)

while True:
    _, frame = cap.read()
    hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    min_h = cv2.getTrackbarPos("Min Hue", "Color Filter")
    max_h = cv2.getTrackbarPos("Max Hue", "Color Filter")
    min_s = cv2.getTrackbarPos("Min Saturation", "Color Filter")
    max_s = cv2.getTrackbarPos("Max Saturation", "Color Filter")
    min_v = cv2.getTrackbarPos("Min Value", "Color Filter")
    max_v = cv2.getTrackbarPos("Max Value", "Color Filter")

    mask = cv2.inRange(hsv_frame, (min_h, min_s, min_v), (max_h, max_s, max_v))
    display = cv2.bitwise_and(frame, frame, mask=mask)

    cv2.imshow("Color Filter", display)
    k = cv2.waitKey(1) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()