<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>SimplePlayer</class>
 <widget class="QMainWindow" name="SimplePlayer">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>640</width>
    <height>480</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Demo Player</string>
  </property>
  <widget class="QWidget" name="centralwidget">
   <layout class="QGridLayout" name="gridLayout_2">
    <item row="0" column="0">
     <widget class="QPushButton" name="openLocal">
      <property name="text">
       <string>Open local file</string>
      </property>
     </widget>
    </item>
    <item row="0" column="1">
     <widget class="QPushButton" name="openUrl">
      <property name="text">
       <string>Open URL</string>
      </property>
     </widget>
    </item>
    <item row="1" column="0" colspan="2">
     <widget class="VlcWidgetVideo" name="video" native="true"/>
    </item>
    <item row="3" column="1">
     <widget class="QPushButton" name="stop">
      <property name="text">
       <string>Stop</string>
      </property>
     </widget>
    </item>
    <item row="3" column="0">
     <widget class="QPushButton" name="pause">
      <property name="text">
       <string>Pause</string>
      </property>
      <property name="checkable">
       <bool>true</bool>
      </property>
     </widget>
    </item>
    <item row="5" column="0" colspan="2">
     <widget class="VlcWidgetVolumeSlider" name="volume" native="true">
      <property name="sizePolicy">
       <sizepolicy hsizetype="Preferred" vsizetype="Maximum">
        <horstretch>0</horstretch>
        <verstretch>0</verstretch>
       </sizepolicy>
      </property>
     </widget>
    </item>
    <item row="6" column="0" colspan="2">
     <widget class="VlcWidgetSeek" name="seek" native="true">
      <property name="sizePolicy">
       <sizepolicy hsizetype="Preferred" vsizetype="Maximum">
        <horstretch>0</horstretch>
        <verstretch>0</verstretch>
       </sizepolicy>
      </property>
     </widget>
    </item>
    <item row="4" column="0">
     <widget class="QPushButton" name="equalizer">
      <property name="text">
       <string>Equalizer</string>
      </property>
     </widget>
    </item>
   </layout>
  </widget>
  <widget class="QMenuBar" name="menubar">
   <property name="geometry">
    <rect>
     <x>0</x>
     <y>0</y>
     <width>640</width>
     <height>21</height>
    </rect>
   </property>
   <widget class="QMenu" name="menuFile">
    <property name="title">
     <string>File</string>
    </property>
    <addaction name="actionOpenLocal"/>
    <addaction name="actionOpenUrl"/>
    <addaction name="separator"/>
    <addaction name="actionQuit"/>
   </widget>
   <widget class="QMenu" name="menuMedia">
    <property name="title">
     <string>Media</string>
    </property>
    <addaction name="actionPause"/>
    <addaction name="actionStop"/>
   </widget>
   <addaction name="menuFile"/>
   <addaction name="menuMedia"/>
  </widget>
  <widget class="QStatusBar" name="statusbar"/>
  <action name="actionQuit">
   <property name="text">
    <string>Quit</string>
   </property>
  </action>
  <action name="actionPause">
   <property name="checkable">
    <bool>true</bool>
   </property>
   <property name="text">
    <string>Pause</string>
   </property>
  </action>
  <action name="actionStop">
   <property name="text">
    <string>Stop</string>
   </property>
  </action>
  <action name="actionOpenLocal">
   <property name="text">
    <string>Open local file</string>
   </property>
  </action>
  <action name="actionOpenUrl">
   <property name="text">
    <string>Open URL</string>
   </property>
  </action>
 </widget>
 <customwidgets>
  <customwidget>
   <class>VlcWidgetVideo</class>
   <extends>QWidget</extends>
   <header location="global">VLCQtWidgets/WidgetVideo.h</header>
   <container>1</container>
   <slots>
    <signal>fullscreen()</signal>
    <slot>toggleFullscreen()</slot>
   </slots>
  </customwidget>
  <customwidget>
   <class>VlcWidgetVolumeSlider</class>
   <extends>QWidget</extends>
   <header location="global">VLCQtWidgets/WidgetVolumeSlider.h</header>
   <container>1</container>
   <slots>
    <slot>mute()</slot>
    <slot>volumeUp()</slot>
    <slot>volumeDown()</slot>
   </slots>
  </customwidget>
  <customwidget>
   <class>VlcWidgetSeek</class>
   <extends>QWidget</extends>
   <header location="global">VLCQtWidgets/WidgetSeek.h</header>
   <container>1</container>
  </customwidget>
 </customwidgets>
 <resources/>
 <connections>
  <connection>
   <sender>actionQuit</sender>
   <signal>triggered()</signal>
   <receiver>SimplePlayer</receiver>
   <slot>close()</slot>
   <hints>
    <hint type="sourcelabel">
     <x>-1</x>
     <y>-1</y>
    </hint>
    <hint type="destinationlabel">
     <x>399</x>
     <y>299</y>
    </hint>
   </hints>
  </connection>
 </connections>
</ui>
