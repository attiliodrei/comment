./configure --with-toolset=clang
b2 toolset=clang
export QT_QPA_PLATFORM_PLUGIN_PATH=/Users/attiliodrei/Qt5.12.0/5.12.0/clang_64/plugins 
export QT_BIN_DIR=/Users/attiliodrei/Qt5.12.0/5.12.0/clang_64 
export LIBVLCQT_INCLUDE_DIR=/Users/attiliodrei/TSUNAMI/src/VLC-Qt_1.1.0_macos/lib/VLCQtCore.framework/Versions/1.1.0/Headers 
export LIBVLCQT_LIBRARY=/Users/attiliodrei/TSUNAMI/src/VLC-Qt_1.1.0_macos                                                    

cd /Users/attiliodrei/Downloads/examples-master/qml-player/build
make 
make install
mv  src/qml-player.app/Contents/MacOS/qml-player src/qml-player.app/Contents/MacOS/qml-player_
cp  -a _qml-player src/qml-player.app/Contents/MacOS/qml-player
cd /Users/attiliodrei/Qt5.12.0/5.12.0/clang_64/bin
                                                                     
./macdeployqt /Users/attiliodrei/Downloads/examples-master/qml-player/build/src/qml-player.app -qmldir=/Users/attiliodrei/Qt5.12.0/5.12.0/clang_64/qml

install_name_tool -add_rpath @executable_path/../Frameworks qml-player_ 
iess-iMac-8:MacOS ies$ install_name_tool -add_rpath @loader_path/../Frameworks qml-player_


 
vlc -vvv /Users/attiliodrei/Desktop/video/tintin.mp4  --sout "#transcode{venc=x264{keyint=60,profile=baseline,level=3.0,nocabac},vcodec=x264,vb=150,scale=0.5,acodec=mp4a,ab=96,channels=2,samplerate=48000}:rtp{dst=15.161.248.116,port=8654,mux=ts,rtsp=tcp}"
%
 vlc -vvv qtsound:// --sout 'sout=#transcode{vcodec=h264,vb=130,fps=5,scale=0.4,acodec=mp4a,ab=40,channels=1,samplerate=44100}:rtp{sdp=rtsp://aws-refector.tngrm.io:8654/gio1}' 

vlc -vvv qtsound://  --rtsp-tcp --sout '#transcode{vcodec=none,acodec=mpga,ab=128,channels=2,samplerate=44100,scodec=none}:rtp{mux="",access="rtsp",dst=15.161.248.116,port=8654}' --no-sout-all --sout-keep


vlc -vvv alsa://plughw:1,0 --sout '#transcode{vcodec=none,acodec=mpga,ab=128,channels=2,samplerate=44100,scodec=none}:rtp{dst=192.168.1.121,port=1234,sdp=rtsp://192.168.1.121:8080/test.sdp}'

vlc -vvv qtsound:// --sout '#transcode{vcodec=none,acodec=mpga,ab=128,channels=2,samplerate=44100,scodec=none}:rtp{mux="",access="rtsp",dst=15.161.248.116,port=8001}' --no-sout-all --sout-keep
vlc -vvv qtsound:// --sout '#transcode{vcodec=none,acodec=mpga,ab=128,channels=2,samplerate=44100,scodec=none}:rtp{dst=15.161.248.116,port=8000,sdp=rtsp://15.161.248.116:8001/gio1.sdp}'

 vlc -vvv  /Users/attiliodrei/Desktop/video/tintin.mp4 --sout "#transcode{venc=x264{keyint=60,profile=baseline,level=3.0,nocabac},vcodec=x264,vb=150,scale=0.5,acodec=mp4a,ab=96,channels=2,samplerate=44100}:rtp{dst=15.161.248.116,port=8000,mux=ts}"

}:rtp{dst=224.10.0.1,port=5004,mux=ts} :sout-keep 
vlc -vvv alsa://plughw:1,0 --sout '#transcode{vcodec=none,acodec=mpga,ab=128,channels=2,samplerate=44100,scodec=none}:rtp{dst=15.161.248.116,port=800,sdp=rtsp://192.168.1.121:8080/test.sdp}'

vlc -vvv qtsound:// --sout '#transcode{vcodec=none,acodec=mpga,ab=128,channels=2,samplerate=44100,scodec=none}:rtp{dst=192.168.1.121,port=1234,sdp=rtsp://192.168.1.121:8080/test.sdp}'

vlc -vvv  /Users/attiliodrei/Desktop/video/tintin.mp4  --sout '#rtp{sdp=rtsp://15.161.248.116:8654/gio1.sdp,mux=ts}'

{mux="",access="rtsp",dst="15.161.248.116:8654/gio1"}

 After reading another forum post it should have looked something like :sout=#transcode{vcodec=h264,vb=130,fps=5,scale=0.4,acodec=mp4a,ab=40,channels=1,samplerate=24000}:rtp{sdp=rtsp://:8554/test.sdp}
 
 -Wno-return-type
 
 15.161.248.116
 sout '#rtp{sdp=rtsp://10.0.0.161:8554/test.sdp,mux=ts}'
 
  vlc -vvv avaudiocapture://AppleHDAEngineInput:1B,0,1,0:1 --sout '#transcode{vcodec=none,acodec=mpga,ab=128,channels=2,samplerate=44100,scodec=none}:rtp{dst=15.161.248.116,port=8654,sdp=rtsp://15.161.248.116:8654/gio1.sdp}'
  vlc -vvv avaudiocapture://AppleHDAEngineInput:1B,0,1,1:2 --sout '#rtp{sdp=rtsp://15.161.248.116:8654/test.sdp,mux=ts}'
  vlc -vvv avaudiocapture://AppleHDAEngineInput:1B,0,1,1:2  --sout "#transcode{vcodec=none,acodec=mp4a,ab=32,channels=1,samplerate=44100}:rtp{dst=15.161.248.116,port=8654,mux=ts}"
 
   vlc -vvv avaudiocapture://AppleHDAEngineInput:1B,0,1,1:2  --rtsp-tcp  --sout "#transcode{vcodec=none,acodec=mp3,ab=256,channels=2,samplerate=44100,scodec=none}:rtp{dst=15.161.248.116,port=8654,mux=ts}"
   vlc -vvv avaudiocapture://AppleHDAEngineInput:1B,0,1,1:2  --rtsp-tcp  --sout "#transcode{vcodec=none,acodec=mp4a,ab=128,channels=2,samplerate=44100,scodec=none}:rtp{dst=192.168.1.219,port=554}"

    vlc -vvv avaudiocapture://AppleHDAEngineInput:1B,0,1,1:2  --rtsp-tcp  --sout "#transcode{vcodec=none,acodec=mpga,ab=128,channels=2,samplerate=44100,scodec=none}
 
   vlc -vvv avaudiocapture://AppleHDA:88 AppleHDAEngineInput:1B,0,1,0:1 --sout '#rtp{sdp=rtsp://192.168.1.219:8654/test.sdp,mux=ts}'
 
 {vcodec=none,acodec=mp3,ab=256,channels=2,samplerate=44100,scodec=none}
 
 standard{access=http,dst=192.168.1.129:80
  vlc -vvv       /Users/attiliodrei/Desktop/video/tintin.mp4  --rtsp-tcp  --sout "#std{access=http, mux=ts, dst=127.0.0.1:80/sample}"
  
[00007fb6f84f0090] avaudiocapture demux debug: avcapture 0/2 AppleHDA:88 AppleHDAEngineInput:1B,0,1,0:1
[00007fb6f84f0090] avaudiocapture demux debug: avcapture 1/2 AppleHDA:88 AppleHDAEngineInput:1B,0,1,1:2

 Consider passing --rtsp-host=IP on the com
ffmpeg -f avfoundation -list_devices true -i ""

ffmpeg -f avfoundation -i ":0" -acodec aac -ab 128k -ac 2  -f rtsp -rtsp_transport tcp rtsp://aws-reflector.tngrm.io:8654/test



auhal audio output debug: DevID: 41 DevName: Built-in Input

vlc alsa://plughw:1,0 --sout='#transcode{vcodec=none,acodec=mp3,ab=256,channels=2,samplerate=44100,scodec=none}:http{mux=mp3,dst=:8080/}' --no-sout-all --sout-keep






 
VlcVideoPlayer {
            id: vidwidget
            anchors.fill: parent
            aspectRatio: tvItem.aspect
            cropRatio: Vlc.Original
            deinterlacing: Vlc.X
            url: "rtmp://ossrs.net:1935/live/livestream" //tvItem.stream
            autoplay: true
            volume: volumeSlider.value
        }



VLCQtCore

    m_media = new VlcMedia("file:///home/vinay/Media Library/lion-sample.webm",m_instance);
    m_media->setOption(":sout=#transcode{vcodec=h264,acodec=mpga,ab=128,channels=2,samplerate=44100,scodec=none}:udp{dst=127.0.0.1:1234}");
    m_media->setOption(":no-sout-all");
    m_media->setOption(":sout-keep");
    


QStringList options="":network-caching=200; :live-caching=150; :rtsp=tcp;:rtsp-caching=50;"
_media->setOption(options):

mediaOptions: ["network-caching=200", "live-caching=150" "rtsp-frame-buffer-size=400000","rtsp=tcp", "rtsp-caching=50"]


QStringList` option_list;
        option_list.append(":network-caching=100");
        option_list.append(":clock-jitter=0");
        option_list.append(":clock-synchro=0");

        _media = new VlcMedia(stream_address, false, _instance);
        _media->setOptions(option_list);
        _player->open(_media);
        
        
libvlc_media_add_option(m_pMedia, ":rtsp=tcp");
libvlc_media_add_option(m_pMedia, ":codec=ffmpeg");
libvlc_media_add_option(m_pMedia, ":avcodec-threads=1");
libvlc_media_add_option(m_pMedia, ":network-caching=200");
libvlc_media_add_option(m_pMedia, ":avcodec-hw=any");    Maybe useful       


   option1 = ":network-caching=150";
    option2 = ":live-caching=150";
    option3 = ":rtsp-caching=50";
    setOption(option1);
    setOption(option2);
    setOption(option2);


edia media = new Media(_libVLC, "rtmp://192.168.214.153:1935/live", FromType.FromLocation); media.AddOption(":network-caching=150"); media.AddOption(":rtsp-caching=50"); _mediaPlayer.Media = media;


options.add("--network-caching=5000");
options.add("--live-caching=5000");
options.add("--sout-mux-caching=5000");
libvlc = new LibVLC(this, options);

void TestMedia::recording()
{
    VlcMedia *media = new VlcMedia(QString(SAMPLES_DIR) + "sample.mp3", true, _instance);
    QCOMPARE(media->duplicate("test", "path", Vlc::AVI), QDir::toNativeSeparators("path/test.avi"));
    QCOMPARE(media->duplicate("test", "path", Vlc::AVI, Vlc::MPEG2Audio, Vlc::MPEG4Video), QDir::toNativeSeparators("path/test.avi"));
    QCOMPARE(media->duplicate("test", "path", Vlc::AVI, Vlc::MPEG2Audio, Vlc::MPEG4Video, 1000, 25, 1), QDir::toNativeSeparators("path/test.avi"));
    QCOMPARE(media->merge("test", "path", Vlc::AVI), QDir::toNativeSeparators("path/test.avi"));
    QCOMPARE(media->record("test", "path", Vlc::AVI, false), QDir::toNativeSeparators("path/test.avi"));
    QCOMPARE(media->record("test", "path", Vlc::AVI, Vlc::MPEG2Audio, Vlc::MPEG4Video, false), QDir::toNativeSeparators("path/test.avi"));
    QCOMPARE(media->record("test", "path", Vlc::AVI, Vlc::MPEG2Audio, Vlc::MPEG4Video, 1000, 25, 1, false), QDir::toNativeSeparators("path/test.avi"));

    delete media;
}

void TestMedia::options()
{
    VlcMedia *media = new VlcMedia(QString(SAMPLES_DIR) + "sample.mp3", true, _instance);
    media->setProgram(1);
    media->setOptions(QStringList() << "option1"
                                    << "option2");
    delete media;



