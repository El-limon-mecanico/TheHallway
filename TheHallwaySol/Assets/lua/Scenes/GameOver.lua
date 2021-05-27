GameOver = {
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
        entities={"Background", "GameOverText","MainMenuButton","SelectLevelButton", "QuitButton"},
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
        GameOverText={
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
                Name = "GameOverText",
                Text = "NO PUEDES ESCAPAR",
                TLColor = "FFA20410",
                TRColor = "FFA20410",
                BLColor = "FFA20410",
                BRColor = "FFA20410",
                Position = {0.21,-0.01  },
                TargetResolution = {1920,1080},
                Size = {1100,250}
            },
        },
        MainMenuButton = {
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
                Name = "GOMainButton",
                Text = "Men� Principal",
                TLColor = "FFA20410",
                TRColor = "FFA20410",
                BLColor = "FFA20410",
                BRColor = "FFA20410",
                Position = {0.3,0.35},
                Size = {750,150},
                TargetResolution = {1920,1080},
                CallBackFunction = "toMenuppl"
            },
        },
        SelectLevelButton = {
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
                Name = "GOSelectButton",
                Text = "Jugar de nuevo",
                TLColor = "FFA20410",
                TRColor = "FFA20410",
                BLColor = "FFA20410",
                BRColor = "FFA20410",
                Position = {0.3,0.55},
                TargetResolution = {1920,1080},
                Size = {750,150},
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
