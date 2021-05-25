menuppl = {
    entities = {"defaultCamera", "sceneLight", "UI"}
}
UI = {
    Active = true,
    Components = {"Transform","AudioSource"},
    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },
    AudioSource={
        Source="MenusTheHallway.wav",
        Volume=1,
        Loops=-1,
        Play=true
    },
    Children = {
        entities={"StartButton","CtrlButton","QuackImage","Title"},
 Title = {
    Active = true,
    Components={"Text","Transform"},
            Transform = {
                Position = {0,0,0},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },
            Text= {
            Active = true,
            Background = false,
            Border = false,
            Style= "TheHallway/StaticText",
            Name = "Title",
            Text = "THE HALLWAY",
            TLColor = "FFA20410",
            TRColor = "FFA20410",
            BLColor = "FFA20410",
            BRColor = "FFA20410",
            Position = {0.25,-0.1  },
            Size = {600,250}
        }
    },
CtrlButton = {
    Active = true,
    Components={"Button","Transform"},
            Transform = {
                Position = {0,0,0},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },
            Button = {
                Active = true,
                Enable = true,
                Type = "Button",
                Style= "TheHallway/Button",
                Name = "CtrlButton",
                Text = "Controles",
                TLColor = "FFA20410",
                TRColor = "FFA20410",
                BLColor = "FFA20410",
                BRColor = "FFA20410",
                Position = {0.3,0.65},
                Size = {400,100},
                CallBackFunction = "toControls"
            }
        },
StartButton = {
    Active = true,
    Components={"Button","Transform"},
            Transform = {
                Position = {0,0,0},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },
            Button={
                Active = true,
                Enable = true,
                Type = "Button",
                Style= "TheHallway/Button",
                Name = "StartButton",
                Text = "Empezar",
                TLColor = "FFA20410",
                TRColor = "FFA20410",
                BLColor = "FFA20410",
                BRColor = "FFA20410",
                Position = {0.3,0.35},
                Size = {400,100},
                CallBackFunction = "toLvlSelector"
            }
        },
    QuackImage={
    Active = true,
    Components={"Image","Transform"},
            Transform = {
                Position = {0,0,0},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },
            Image={ 
                Active = true,
                Style= "TheHallway/StaticImage",
                Name = "QuackEngine",
                Image = "quackEngine.png",
                Position = {0.9,0.85},
                Size = {100,100},
                Background=false,
                Border=false
            }
        },
    }
}
sceneLight = {
    Active = true,
    Components = {"Transform", "Light"},

    Transform = {
        Position = {-10,10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Light = {
        LightType = 1,
        DiffuseColor = {1,1,1},
        SpecularColor = {1,1,1},
        Direction = {0,0,0},
        Distance = 100,
        InnerAngle = 30,
        OuterAngle = 90,
        isOn = true
    }
}
defaultCamera = {
    Active = true,
    Components = {"Transform", "Camera"},

    Transform = {
        Position = {10,10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {   
        Name = "MainCam",
        Background = {0.46,0.49,0.48},
        LookAt = {0,0,0},
        Width = 1,
        Height = 1,
        xProp = 16,
        yProp = 9,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective",
        zOrder = 0
    },
}