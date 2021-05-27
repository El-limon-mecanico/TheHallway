Pause = {
    entities = {"defaultCamera", "sceneLight","UI"}
}

UI = {
    Active=true,
    Components = {"Transform","AudioSource"},
    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },
    AudioSource={
        Source= "MenusTheHallway.wav",
        Volume=0.25,
        Loops=-1,
        Play=true
    },
    Children={
        entities={"Background", "ResumeText","ResumeButton","ControlButton", "QuitButton"},
        Background={
            Active= true,
            Components={"Image", "Transform"},
            Transform = {
                Position = {0,0,0},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },
            Image={
                Active = true,
                Style= "TheHallway/StaticImage",
                Name = "MenuBackground",
                Image = "menuBackground.png",
                TargetResolution = {1920,1080},
                Position = {0,0},
                Size = {1920,1080},
                Background=false,
                Border=false
            },
        },
        ResumeText={
            Active= true,
            Components={"Text", "Transform"},
            Transform = {
                Position = {0,0,0},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },
            Text={
                Active = true,
                Background = false,
                Border = false,
                Style= "TheHallway/StaticText",
                Name = "WinText",
                Text = "PAUSA",
                TLColor = "FFA20410",
                TRColor = "FFA20410",
                BLColor = "FFA20410",
                BRColor = "FFA20410",
                Position = {0.41,-0.01 },
                TargetResolution = {1920,1080},
                Size = {370,250}
            },
        },
        ResumeButton = {
            Active =true,
            Components={"Button", "Transform"},
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
                Name = "ResumeButton",
                Text = "Continuar",
                TLColor = "FFA20410",
                TRColor = "FFA20410",
                BLColor = "FFA20410",
                BRColor = "FFA20410",
                Position = {0.36,0.35},
                TargetResolution = {1920,1080},
                Size = {525,150},
                CallBackFunction = "back"
            },
        },
        ControlButton = {
            Active =true,
            Components={"Button", "Transform"},
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
                Name = "ControlesButton",
                Text = "Controles",
                TLColor = "FFA20410",
                TRColor = "FFA20410",
                BLColor = "FFA20410",
                BRColor = "FFA20410",
                Position = {0.36,0.7},
                TargetResolution = {1920,1080},
                Size = {525,150},
                CallBackFunction = "toControls"
            },
        },
    
        QuitButton = {
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
                Name = "QuitButton",
                Text = "x",
                TLColor = "FFA20410",
                TRColor = "FFA20410",
                BLColor = "FFA20410",
                BRColor = "FFA20410",
                Position = {0.9,0.01},
                TargetResolution = {1920,1080},
                Size = {100,100},
                CallBackFunction = "toQuitScene"
            }
        }
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
