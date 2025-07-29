# Installing OpenCV 4.8.0 with `opencv_contrib` on Ubuntu 24.04

If you already have OpenCV installed on Ubuntu but do not have the `opencv_contrib` modules, you will need to **reinstall OpenCV** to include these additional modules. The `opencv_contrib` modules aren't typically included in the standard pre-built OpenCV packages and must be manually compiled along with OpenCV.

The **SURF** algorithm, since it is **patented**, is included in the `opencv_contrib` repository and **requires setting the `OPENCV_ENABLE_NONFREE` flag** during compilation to use it.

---

## Steps to Build OpenCV with `opencv_contrib` Modules
## Step 1: Install Dependencies

```bash
sudo apt update
sudo apt install -y build-essential cmake git pkg-config libgtk-3-dev \
    libavcodec-dev libavformat-dev libswscale-dev libv4l-dev \
    libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev \
    gfortran openexr libatlas-base-dev python3-dev python3-numpy \
    libtbb2 libtbb-dev libdc1394-22-dev libgflags-dev libgoogle-glog-dev
```

## Step 2: Clone OpenCV and opencv_contrib Repositories (version 4.8.0)

```bash
cd ~/Downloads
git clone https://github.com/opencv/opencv.git
cd opencv
git checkout 4.8.0

cd ..
git clone https://github.com/opencv/opencv_contrib.git
cd opencv_contrib
git checkout 4.8.0
```

## Step 3: Create a Build Directory

```bash
cd ~/Downloads/opencv
mkdir build
cd build
```

## Step 4: Run CMake Configuration

```bash
cmake -D CMAKE_BUILD_TYPE=Release \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
      -D OPENCV_ENABLE_NONFREE=ON \
      -D BUILD_EXAMPLES=ON \
      -D WITH_CUDA=OFF \
      ..
```

## Step 5: Build OpenCV

```bash
make -j$(nproc)
```

## Step 6: Install OpenCV

```bash
sudo make install
sudo ldconfig
```

---

✅ You now have OpenCV 4.8.0 installed with `opencv_contrib` and `nonfree` modules (like SURF) enabled on Ubuntu 24.04.
