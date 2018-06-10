# mtcnn_face_detection_and_tracking
An MTCNN based face detection and an optical-flow based tracking running in two threads.

## face detection
An MTCNN based face detector modified from [https://github.com/deepinsight/mtcnn-ncnn](https://github.com/deepinsight/mtcnn-ncnn)  
Its implementation is based on the deeplearning platform [ncnn](https://github.com/Tencent/ncnn)

## tracking
An optical-flow and Kalman Filter based multiple object tracker, more details: [https://github.com/zlingkang/multi_object_tracker](https://github.com/zlingkang/multi_object_tracker)

## Usage
* Compile ncnn  
go to 3rd_party/mtcnn-ncnn/ and  
`mkdir build`  
`cd build`  
`cmake ..`  
`make`  
* Compile mtcnn face detector  
go to 3rd_party/mtcnn-ncnn/mtcnn/ and
`mkdir build`  
`cd build`  
`cmake ..`  
`make`  
* Compile the tracker  
in the repo root directory, modify the OpenCV path in CMakeLists.txt and  
`mkdir build`  
`cd build`  
`cmake ..`  
`make`  

* Run  
go to build/ and  
`./multi_thread_det_and_track`  
make sure USB camera is plugged in, otherwise if reading from video, modify main.cpp line 10 and 27.

## Other notice
* Running on embedded platform (Raspberry Pi, Odroid ...)  
When compiling ncnn, in 3rd_party/mtcnn-ncnn/src/, copy CMakeLists_arm.txt to CMakeLists.txt,  
and add `add_definitions(-mfpu=neon)` in 3rd_party/mtcnn-ncnn/CMakeLists.txt.  
This will make the face detection much faster.
* Tune tracker's parameters  
checkout [https://github.com/zlingkang/multi_object_tracker](https://github.com/zlingkang/multi_object_tracker)
