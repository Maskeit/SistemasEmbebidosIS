import cv2
import torch
from tracker import *
from pynput import keyboard as kb
import numpy as np
import time
import threading

model = torch.hub.load('ultralytics/yolov5', 'yolov5s', pretrained=True)

cap = cv2.VideoCapture(0)
cv2.namedWindow('FRAME')

tracker = Tracker()
area_1 = [(377, 315), (429, 373), (535, 339), (500, 296)]
area1 = set()

def POINTS(event, x, y, flags, param):
    if event == cv2.EVENT_MOUSEMOVE:
        colorsBGR = [x, y]
        print(colorsBGR)

cv2.setMouseCallback('FRAME', POINTS)

def detect_objects():
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        frame = cv2.flip(frame, 1)
        results = model(frame)
        # frame = np.squeeze(results.render())
        list = []
        for index, row in results.pandas().xyxy[0].iterrows():
            x1 = int(row['xmin'])
            y1 = int(row['ymin'])
            x2 = int(row['xmax'])
            y2 = int(row['ymax'])
            b = str(row['name'])
            if 'person' in b:
                list.append([x1, y1, x2, y2])
        boxes_ids = tracker.update(list)
        for box_id in boxes_ids:
            x, y, w, h, id = box_id
            cv2.rectangle(frame, (x, y), (w, h), (255, 0, 255), 2)
            # cv2.putText(frame,str(id),(x,y), cv2.FONT_HERSHEY_PLAIN,3, (255,0,0),3)
        cv2.imshow('SMART CROWD', frame)
        if cv2.waitKey(1) == 27:
            break

def listen_keyboard():
    while True:
        numBoxes = len(tracker.update([]))
        print(numBoxes)
        # time.sleep(0.1)

def main():
    threading.Thread(target=detect_objects).start()
    threading.Thread(target=listen_keyboard).start()
    cv2.waitKey(0)

if __name__ =="__main__":
    main()