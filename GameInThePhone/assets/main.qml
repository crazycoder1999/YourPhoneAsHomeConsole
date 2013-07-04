// Navigation pane project template
import bb.cascades 1.0

NavigationPane {
    id: navigationPane
    Page {
        // page with a picture thumbnail
        Container {
            background: Color.Black
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight;
            }
          /*  Button {
                horizontalAlignment: HorizontalAlignment.Center
                text: qsTr("Go");
                onClicked: {
                    cpp.startWS();
                }
            }
            Button {
                horizontalAlignment: HorizontalAlignment.Center
                text: qsTr("Stop");
                onClicked: {
                    cpp.stopWS();
                }    
            }*/
            ImageButton {
                
                            horizontalAlignment: HorizontalAlignment.Center
                            verticalAlignment: VerticalAlignment.Center
                            defaultImageSource: "asset:///images/leftButton.png";
                            onClicked: {
                               // cpp.moveRight();
                            }    
                            onTouch: {
                            console.log(event.touchType);
                              if (event.touchType == 2) { //up???
                                  cpp.release();
                                }    
                            if(event.touchType < 2) {
                                    cpp.moveLeft();
                                }
                            }
            }
            ImageButton {
                            horizontalAlignment: HorizontalAlignment.Center
                            verticalAlignment: VerticalAlignment.Center
                            defaultImageSource: "asset:///images/fireButton.png";
                            onClicked: {
                               // cpp.moveRight();
                            }    
                            onTouch: {
                            console.log(event.touchType);
                              if (event.touchType == 2) { //up???
                                  cpp.release();
                                }    
                            if(event.touchType < 2) {
                                    cpp.fire();
                                }
                            }
            }
            ImageButton {
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                defaultImageSource: "asset:///images/rightButton.png";
                onClicked: {
                   // cpp.moveRight();
                }    
                onTouch: {
                console.log(event.touchType);
                  if (event.touchType == 2) { //up???
                      cpp.release();
                    }    
                if(event.touchType < 2) {
                        cpp.moveRight();
                    }
                }
            }

        }
    }
    onCreationCompleted: {
        // this slot is called when declarative scene is created
        // write post creation initialization here
        console.log("NavigationPane - onCreationCompleted()");

        // enable layout to adapt to the device rotation
        // don't forget to enable screen rotation in bar-bescriptor.xml (Application->Orientation->Auto-orient)
        OrientationSupport.supportedDisplayOrientation = SupportedDisplayOrientation.All;
    }
}
