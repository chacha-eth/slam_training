cmake_minimum_required(VERSION 3.10)

#add executable 
add_executable( orb_descriptor orb_descriptor.cpp)
add_executable( brief_descriptor brief_descriptor.cpp)
add_executable( freak_descriptor freak_descriptor.cpp)
add_executable( brisk_descriptor brisk_descriptor.cpp)
add_executable( sift_descriptor sift_descriptor.cpp)
add_executable( surf_descriptor surf_descriptor.cpp)
# link libraries
target_link_libraries( orb_descriptor ${OpenCV_LIBS})
target_link_libraries( brief_descriptor ${OpenCV_LIBS})
target_link_libraries( freak_descriptor ${OpenCV_LIBS})
target_link_libraries( brisk_descriptor ${OpenCV_LIBS})
target_link_libraries( sift_descriptor ${OpenCV_LIBS})
target_link_libraries( surf_descriptor ${OpenCV_LIBS})

# Define a custom target to group them
add_custom_target(lab3
  DEPENDS orb_descriptor sift_descriptor surf_descriptor freak_descriptor brisk_descriptor brief_descriptor
)
# copy required images to every directory with executable 
set(IMAGES
    ${CMAKE_SOURCE_DIR}/data/img0.png
    ${CMAKE_SOURCE_DIR}/data/img1.png
    ${CMAKE_SOURCE_DIR}/data/img2.png
)
file(COPY ${IMAGES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})




