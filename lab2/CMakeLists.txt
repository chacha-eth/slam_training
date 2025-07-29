cmake_minimum_required(VERSION 3.10)

#add executable 
add_executable( fast_detector fast_detector.cpp)
add_executable( orb_detector orb_detector.cpp)
add_executable( sift_detector sift_detector.cpp)
add_executable( surf_detector surf_detector.cpp)
# link libraries
target_link_libraries( fast_detector ${OpenCV_LIBS})
target_link_libraries( orb_detector ${OpenCV_LIBS})
target_link_libraries( sift_detector ${OpenCV_LIBS})
target_link_libraries( surf_detector ${OpenCV_LIBS})

# Define a custom target to group them
add_custom_target(lab2
  DEPENDS fast_detector orb_detector sift_detector surf_detector
)
# copy required images to every directory with executable 
set(IMAGES
    ${CMAKE_SOURCE_DIR}/data/img0.png
    ${CMAKE_SOURCE_DIR}/data/img1.png
    ${CMAKE_SOURCE_DIR}/data/img2.png
)
file(COPY ${IMAGES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})




