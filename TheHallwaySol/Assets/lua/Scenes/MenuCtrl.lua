menuctrl = {
    entities = {"defaultCamera", "sceneLight","UI"}
}

UI = {
    Components = {"Scheme","QuackImage","BackButton"},
    Scheme={
        Type="Scheme",
        Scheme="TheHallway.scheme"
    },
    QuackImage={
        Type = "Image",
        Style= "TheHallway/StaticImage",
        Name = "MenuCtrlImage",
        Image = "MenuCtrl.png",
        Position = {0,0},
        Size = {1000,700}
    },
    BackButton = {
        Type = "Button",
        Style= "TheHallway/Button",
        Name = "volverButton",
        Text = "<-",
        Position = {0.001,0.01},
        Size = {100,50},
        CallBackFunction = "controlsToMenuppl"
    },
}
sceneLight = {
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
    Components = {"Transform", "Camera"},

    Transform = {
        Position = {10,10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Name = "MainCam",
        Background = {0,0,1},
        LookAt = {0,0,0},
        Width = 0,
        Height = 0,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective"
    },
}
