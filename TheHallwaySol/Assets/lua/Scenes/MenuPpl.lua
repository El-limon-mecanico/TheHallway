menuppl = {
    entities = {"defaultCamera", "sceneLight", "UI"}
}
UI = {
    Components = {"Scheme","Text1", "CtrlButton", "StartButton","QuackImage"},
    Scheme={
        Type="Scheme",
        Scheme="TheHallway.scheme"
    },
    Text1 = {
        Type = "Text",
        Style= "TheHallway/StaticText",
        Name = "Texto",
        Text = "THE HALLWAY",
        Position = {0.25,-0.1  },
        Size = {600,250}
    },
    CtrlButton = {
        Type = "Button",
        Style= "TheHallway/Button",
        Name = "CtrlButton",
        Text = "Controles",
        Position = {0.3,0.65},
        Size = {400,100},
        CallBackFunction = "menupplToControls"
    },
    StartButton = {
        Type = "Button",
        Style= "TheHallway/Button",
        Name = "StartButton",
        Text = "Empezar",
        Position = {0.3,0.35},
        Size = {400,100},
        CallBackFunction = "menupplToGame"
    },
    QuackImage={
        Type = "Image",
        Style= "TheHallway/StaticImage",
        Name = "QuackEngine",
        Image = "quackEngine.png",
        Position = {0.85,0.8},
        Size = {100,100}
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
        Background = {0.46,0.49,0.48},
        LookAt = {0,0,0},
        Width = 0,
        Height = 0,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective"
    },
}