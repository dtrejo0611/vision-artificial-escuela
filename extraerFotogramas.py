# -*- coding: utf-8 -*-
"""
Created on Thu Jun  5 15:36:09 2025

@author: dtrej
"""

import cv2
import os

# Ruta al video
video_path = 'ruta/del/video.mp4'
# Carpeta de salida
output_folder = 'fotogramas'

# Crear carpeta si no existe
os.makedirs(output_folder, exist_ok=True)

# Cargar el video
cap = cv2.VideoCapture(video_path)

frame_number = 0

while True:
    ret, frame = cap.read()
    if not ret:
        break  # Fin del video

    # Guardar el fotograma
    frame_filename = os.path.join(output_folder, f'frame_{frame_number:05d}.jpg')
    cv2.imwrite(frame_filename, frame)
    frame_number += 1

cap.release()
print(f"Se extrajeron {frame_number} fotogramas.")
