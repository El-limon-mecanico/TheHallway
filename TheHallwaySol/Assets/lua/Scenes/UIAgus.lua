scene1 = {
    entities = {"defaultCamera", "sceneLight", "UI"}
}
UI = {
    Components = {"Prueba","Text1", "CtrlButton", "StartButton"},
    Prueba={
        Type="Scheme",
        Scheme="UITry.scheme"
    },
    Text1 = {
        Type = "Text",
        Style= "UITry/StaticText",
        Name = "Texto",
        Text = "THE HALLWAY",
        Position = {0.25,-0.1  },
        Size = {600,250}
    },
    CtrlButton = {
        Type = "Button",
        Style= "UITry/Button",
        Name = "CtrlButton",
        Text = "Controles",
        Position = {0.3,0.65},
        Size = {400,100},
        CallBackFunction = "botonPresionado"
    },
    StartButton = {
        Type = "Button",
        Style= "UITry/Button",
        Name = "StartButton",
        Text = "Empezar",
        Position = {0.3,0.35},
        Size = {400,100},
        CallBackFunction = "botonPresionado"
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