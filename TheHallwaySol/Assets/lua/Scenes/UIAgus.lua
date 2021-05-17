scene1 = {
    entities = {"defaultCamera", "sceneLight", "UI"}
}
UI = {
    Components = {"Prueba","Text1", "Image1", "Button1"},
    Prueba={
        Type="Scheme",
        Scheme="UITRY.scheme"
    },
    Text1 = {
        Type = "Text",
        Style= "AlfiskoSkinLook/StaticText",
        Name = "Texto",
        Text = "THE HALLWAY",
        Position = {0,0},
        Size = {405,50}
    },

    Image1 = {
        Type = "Image",
        Style= "AlfiskoSkinLook/StaticImage",
        Name = "Cuchao",
        Image = "cuchao.png",
        Position = {0.1,0.6},
        Size = {300,200}
    },

    Button1 = {
        Type = "Button",
        Style= "AlfiskoSkinLook/Button",
        Name = "Button",
        Text = "Betis",
        Position = {0.5,0.5},
        Size = {100,100},
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
        Background = {1,1,0},
        LookAt = {0,0,0},
        Width = 0,
        Height = 0,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective"
    },
}