MenuPpl = {
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
        Volume=0.25,
        Loops=-1,
        Play=true
    },
    Children = {
        entities={"Background", "StartButton","CtrlButton","QuackImage","Title", "FullScreenButton","QuitButton"},
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
                Position = {0.3,-0.01},
                Size = {775,250},
                TargetResolution = {1920,1080},
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
                Position = {0.39,0.35},
                TargetResolution = {1920,1080},
                Size = {525,150},
                CallBackFunction = "toLvlSelector"
            }
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
                        Size = {100,100},
                        CallBackFunction = "toQuitScene"
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
                TargetResolution = {1920,1080},
                Position = {0.9,0.85},
                Size = {100,100},
                Background=false,
                Border=false
            }
        },
        
        FullScreenButton = {
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
                Name = "fullscreenButton",
                Text = "Fullscreen",
                TLColor = "FFA20410",
                TRColor = "FFA20410",
                BLColor = "FFA20410",
                BRColor = "FFA20410",
                Position = {0.39,0.55},
                TargetResolution = {1920,1080},
                Size = {525,150},
                CallBackFunction = "fullscreen"
            },
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
                Position = {0.39,0.75},
                Size = {525,150},
                CallBackFunction = "toControls",
                TargetResolution = {1920,1080},
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