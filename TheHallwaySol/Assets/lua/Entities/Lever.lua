Manivela ={
    Active = true,
    Tag = "Manivela",
    Components = {"Transform","MeshRenderer", "Rigidbody", "Lever"},

    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    MeshRenderer ={
        Mesh = "Cube",
    },

    Rigidbody = {
        Type = "Box",
        Mass = 1,
        Trigger = true,
        Static = true,
        PositionConstrains = {1,1,1},
        RotationConstrains = {1,1,1}
    },

    Lever = {
        Total = 10,
        ChargingVel = 1,
        UncharginVel = 0.5
    }
}