import cv2

img = cv2.imread("./assets/triangle.png", cv2.IMREAD_GRAYSCALE)
gray = cv2.cvtColor(img, cv2.IMREAD_GRAYSCALE)

ret, thresh = cv2.threshold(img, 1, 255, cv2.THRESH_BINARY_INV)
contours,h = cv2.findContours(thresh, 1, 2)

for cnt in contours:
    approx = cv2.approxPolyDP(cnt, 0.01*cv2.arcLength(cnt, True), True)
    if len(approx) == 3:
        print("triangle")
    elif len(approx) == 4:
        print("square")