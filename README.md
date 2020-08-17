# 双目摄像头标定程序
编译后生成get_Images和calib两个可执行文件
## get_Images
运行get_Images会调用外部摄像头，按<kbd>space</kbd>拍摄，拍摄约20-30张后按<kbd>q</kbd>退出
左右图会分别保存在`pic/left/`和`pic/right/`下，同时`pic`下生成文件列表`stereo_calib.txt`

## calib
工作空间下创建文件夹：`pic/`其下创建`pic/left/`和`pic/right/`
运行calib会按文件列表`stereo_calib.txt`，从`pic/left/`和`pic/right/`下读取图片标定，观察均方根误差RMS，内外参分别写入`intrinsics.yaml`和`	extrinsics.yaml`

