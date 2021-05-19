menuctrl = {
    entities = {"defaultCamera", "sceneLight","UI"}
}

UI = {
    Active=true,
    Components = {"Transform"},
    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },
    Children={
        entities={"CtrlImage","BackButton"},
        CtrlImage={
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
                Name = "MenuCtrlImage",
                Image = "MenuCtrl.png",
                Position = {0,0},
                Size = {1000,700}
                },
        },
        BackButton = {
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
            Name = "backButton",
            Text = "<-",
            TLColor = "FFA20410",
            TRColor = "FFA20410",
            BLColor = "FFA20410",
            BRColor = "FFA20410",
            Position = {0.001,0.01},
            Size = {100,50},
            CallBackFunction = "controlsToMenuppl"
        },
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
        Name = "MenuCtrl",
        Background = {0.46,0.49,0.48},
        LookAt = {0,0,0},
        Width = 0,
        Height = 0,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective"
    },
}
