# Qt VLC Video Player

## Overview
This is a cross-platform video player application built using Qt and libVLC, providing a simple and lightweight video playback solution with a user-friendly interface. The application allows users to load and play video files directly through a straightforward graphical interface.

## Features
- Seamless video playback using libVLC
- User-friendly GUI with integrated video frame
- Direct video path input
- Simple video loading mechanism
- Cross-platform compatibility (Windows, macOS, Linux)

## Prerequisites
### Dependencies
- Qt 5 or Qt 6
- libVLC 3.0.20 or higher
- C++17 compatible compiler
- CMake (minimum version 3.5)

### System Requirements
- Windows 10/11, macOS 10.15+, or Linux (Ubuntu 20.04+)
- Minimum 4GB RAM
- 100MB free disk space
- OpenGL 3.3 compatible graphics card

## Installation

### Build Prerequisites
1. Install Qt from the official website (https://www.qt.io/download)
   - Recommended: Qt 6.x with Qt Creator
2. Install VLC from VideoLAN (https://www.videolan.org/vlc/)
3. Install CMake (https://cmake.org/download/)

### Compilation Steps
```bash
# Clone the repository
git clone https://github.com/yourusername/qt-vlc-video-player.git
cd qt-vlc-video-player

# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
cmake --build . --config Release
```

## Usage Instructions
1. Launch the application
2. In the text input field, enter the full path to your video file
   - Example: `C:\Videos\myvideo.mp4` or `/home/user/Videos/myvideo.mp4`
3. Click the "Load Video" button
4. The video will start playing in the integrated video frame

## Supported Video Formats
The application supports all formats compatible with VLC, including:
- MP4
- AVI
- MKV
- MOV
- WMV
- WEBM
- FLV

## Customization Options
You can modify the following in `mainwindow.cpp`:
- Video frame dimensions
- Initial window size
- Additional playback controls

## Troubleshooting
- Verify VLC is correctly installed
- Ensure library paths in `CMakeLists.txt` match your system
- Check that video path is correct and file exists
- Confirm you have the latest VLC and Qt versions

## Known Limitations
- No advanced playback controls in current version
- Single video playback at a time
- Minimal error handling

## Future Roadmap
- Add pause/stop/seek controls
- Implement playlist functionality
- Enhance error handling and user notifications

## Contributing
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License
Distributed under the MIT License. See `LICENSE` for more information.
